/*
 * file:     gds_rap_p04.c
 * unit:     yes
 * function: func_021D7770, func_021D7808
 * address:  0x021D7770
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
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021DA040 0x021DA040 data a4
 *   func_021D8588 0x021D8588 arm ov125
 *   func_021D7CF4 0x021D7CF4 arm ov125
 *   func_021D7CD4 0x021D7CD4 arm ov125
 *   func_021D7F60 0x021D7F60 arm ov125
 *   func_021D7C90 0x021D7C90 arm ov125
 *   func_021D858C 0x021D858C arm ov125
 */
#include "../../matched/include/G_Clear.h"

typedef struct { int words[78]; } Record;

typedef struct { Record record; int f138; char pad13c[4]; char name[256]; char pad240[24]; int f258; char pad25c[16]; int f26c; } State;

extern void func_021D8588(void);
extern int func_021D7CF4(void);
extern int func_021D7CD4(void);
extern char *func_02094798(char *, const char *);
extern void func_021D7F60(void);
extern void func_021D7C90(int);
extern void func_021D858C(void);
int func_021D7770(const char *a, unsigned short b, Record *src);
void func_021D7808(void);
extern State d_021D9E40;
extern char d_021DA040[];

static inline Record *copy(Record *dst, const Record *src) { *dst = *src; return dst; }

int func_021D7770(const char *a, unsigned short b, Record *src)
{
    if (src) {
        d_021D9E40.record = *src;
        d_021D9E40.f138 = 0;
    }
    func_021D8588();
    if (!func_021D7CF4()) return 0;
    func_021D7CD4();
    func_02094798(d_021D9E40.name, a);
    *(short *)(d_021DA040 + 0x40) = b;
    d_021D9E40.f258 = 0;
    d_021D9E40.f26c = -1;
    func_021D7808();
    return 1;
}

void func_021D7808(void) {
 func_021D7F60();
 if(((int *)&d_021D9E40)[0x258/4]) {
  func_021D7C90(((int *)&d_021D9E40)[0x258/4]);
  ((int *)&d_021D9E40)[0x258/4]=0;
 }
 ((int *)&d_021D9E40)[0x244/4]=15;
 ((int *)&d_021D9E40)[0x248/4]=30;
 ((int *)&d_021D9E40)[0x24c/4]=30;
 ((int *)&d_021D9E40)[0x254/4]=0;
 ((int *)&d_021D9E40)[0x25c/4]=0;
 ((int *)&d_021D9E40)[0x260/4]=0;
 ((int *)&d_021D9E40)[0x264/4]=0;
 ((int *)&d_021D9E40)[0x268/4]=0;
 ((int *)&d_021D9E40)[0x13c/4]=1;
 ((int *)&d_021D9E40)[0x250/4]=0;
 func_021D858C();
}
