#ifndef UTIL_H
#define UTIL_H

void err_sys (char *fmt, ...);
void err_quit (char *fmt, ...);
char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);
int sock_cmp_addr(const struct sockaddr *sa1,
		  const struct sockaddr *sa2, socklen_t salen);
void tv_sub (struct timeval *out, struct timeval *in);
char *icmpcode_v4(int code);
Sigfunc *Signal(int signo, Sigfunc *func);
void *Calloc(size_t n, size_t size);
void Gettimeofday(struct timeval *tv, void *foo);
void Pipe(int *fds);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Setsockopt(int fd, int level, int optname, const void *optval,
		socklen_t optlen);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Write(int fd, void *ptr, size_t nbytes);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr);
struct addrinfo *Host_serv(const char *host, const char *serv,
			   int family, int socktype);

#endif
