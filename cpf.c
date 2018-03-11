#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[]) {
  int fdi;
  int fdo;

  ssize_t ret_in, ret_out;

  char buf[256];

  fdi = open(argv[1], O_RDONLY);

  fdo = open(argv[2], O_CREAT | O_WRONLY, 0644);

  while ((ret_in = read(fdi, &buf, 256)) > 0) {
    ret_out = write(fdo, &buf, (ssize_t) ret_in);
  }

  close(fdi);
  close(fdo);
  return 0;
}
