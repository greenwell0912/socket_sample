#include <stdio.h>
#include <arpa/inet.h>
#include <string.h> // memset
#include <unistd.h> // close function

int main() {
  /* IP アドレス、ポート番号、ソケット */
  char dest[80];
  unsigned short port = 1234;
  int dstSocket;
  int i;

  /* sockaddr_in 構造体 */
  struct sockaddr_in dstAddr;

  /* 各種パラメータ */
  char *toSendText = "This is a test";

  /************************************************************/
  /* 相手先アドレスの入力 */
  printf("Connect to ? : (name or IP address) ");
  if (fgets(dest, sizeof(dest), stdin) == NULL) {
    if (puts("EOF or read error\n") == EOF) {
      /* エラー処理 */
      return -1;
    }
  }

  /* sockaddr_in 構造体のセット */
  memset(&dstAddr, 0, sizeof(dstAddr));
  dstAddr.sin_port = htons(port);
  dstAddr.sin_family = AF_INET;
  dstAddr.sin_addr.s_addr = inet_addr(dest);
 
  /* ソケット生成 */
  dstSocket = socket(AF_INET, SOCK_STREAM, 0);

  /* 接続 */
  printf("Trying to connect to %s: \n", dest);
  connect(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr));

  /* パケット送出 */
  for(i=0; i<10; i++) {
    printf("sending...\n");
    send(dstSocket, toSendText, strlen(toSendText)+1, 0);
    sleep(1);
  }

  /* ソケット終了 */
  close(dstSocket);
}
