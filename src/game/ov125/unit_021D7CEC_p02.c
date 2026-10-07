/*
 * file:     unit_021D7CEC_p02.c
 * unit:     yes
 * function: func_021D7D88, func_021D7E20
 * address:  0x021D7D88
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215F650 0x0215F650 arm ov009
 *   func_0215FA9C 0x0215FA9C arm ov009
 */
#include "../../matched/include/Obj23010.h"

extern void *func_0215F650(const char *);
extern char *func_0215FA9C(unsigned);
extern char *func_02094798(char *dst, const char *src);
int func_021D7D88(const char *s);
int func_021D7E20(const char *s, char *out);

int func_021D7D88(const char *s) {
 int digits=0, dots=0;
 while (*s) {
  if (*s >= '0' && *s <= '9') {
   if (++digits >= 4) return 0;
  } else if (*s == '.') {
   if (digits == 0) return 0;
   ++dots;
   digits=0;
   if(dots >= 4) return 0;
  } else return 0;
  ++s;
 }
 if(dots==3 && digits!=0) return 1;
 return 0;
}

int func_021D7E20(const char *s, char *out) {
 void *p;
 if (!func_021D7D88(s)) {
  p=func_0215F650(s);
  if (p) {
   func_02094798(out, func_0215FA9C(***(unsigned ** *)&((struct Obj23010 *)p)->fC));
  } else return 0;
 } else {
  func_02094798(out,s);
 }
 return 1;
}
