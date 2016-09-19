#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#define X(x) (x) % 9
#define Y(x) ((x) / 9) + 1
#define B(x) 3 * ((Y(x) - 1) / 3) + X(x) / 3
#define	YB(x) ((x) / 3 + (b / 3) * 3) + 1
#define XB(x) (x) % 3 + (b % 3) * 3
#define ISNUM(x) (x) >= '0' && (x) <= '9'
#define ALLOWED(x) (x) == '.' || ISNUM(x)

#endif
