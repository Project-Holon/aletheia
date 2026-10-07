/*
 * file:     unit_021D85C0_p04.c
 * unit:     yes
 * function: func_021D958C, func_021D9760, func_021D97B8, func_021D97CC
 * address:  0x021D958C
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_021D9E98 0x021D9E98 thumb ov129
 *   func_021D93D4 0x021D93D4 thumb ov129
 *   func_021D9320 0x021D9320 thumb ov129
 *   func_021D9348 0x021D9348 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 *   func_021D9E48 0x021D9E48 thumb ov129
 *   func_021D9EE8 0x021D9EE8 thumb ov129
 *   func_021D9564 0x021D9564 thumb ov129
 *   func_021DA158 0x021DA158 thumb ov129
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D8950 0x021D8950 thumb ov129
 *   func_021DA164 0x021DA164 thumb ov129
 *   func_021DA1A8 0x021DA1A8 thumb ov129
 *   func_021D9E60 0x021D9E60 thumb ov129
 */
#include "../../matched/include/Obj00361.h"
#include "../../matched/include/Obj23117.h"

struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16_021D958C;

typedef struct { int state, value, flag; struct Obj *handle; char tail[12]; } Record;

typedef unsigned char  u8;

typedef signed char s8;

typedef signed short s16_021D97B8;

typedef signed int s32;

typedef short s16_021D97CC;

extern void func_020061E4(u32 a);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021D9E98(char *p, int i);
extern void func_021D93D4(char *p);
extern int func_021D9320(u8 *p);
extern void func_021D9348(char *p);
extern void func_021D8AF4(char *p, int v);
extern void func_021D9E48(char *p, int i, int a);
extern void func_021D9EE8(char *p, int i, int j);
extern void func_021D9564(u8 *p, int n);
extern int func_021DA158(int x, int flag);
extern void func_021D8950(char *,int);
extern void func_021DA164(void *);
extern void func_021DA1A8(char *,int);
extern void func_021D9E60(u8 *p, int n);
void func_021D958C(u32 n, int touch, char *p);
void func_021D9760(char *p);
void func_021D97B8(char *p);
int func_021D97CC(u8 *p,int value);


void func_021D958C(u32 n, int touch, char *p)
{
    Record *r = (Record *)p;
    int idx, v, k;
    int m;
    if (*(int *)(p + 0x22C) != 1) return;
    if (*(int *)(p + 0x2FC) != 1) *(int *)(p + 0x2FC) = 1;
    if (touch == 0) {
        {
            if (n <= 11) {
                if (r[n].flag == 1) {
                    *(int *)(p + 0x31C) = 2;
                    *(int *)(p + 0x320) = n;
                } else {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = r[n].value;
                }
                func_020061E4(1352);
            } else if (n == 22) {
                *(s16_021D958C *)(p + 0x1B8) = 0;
                *(s16_021D958C *)(p + 0x1BA) = 2;
                func_020061E4(1363);
                func_021D93D4(p);
            } else if (n == 23) {
                *(s16_021D958C *)(p + 0x1B8) = 3;
                *(s16_021D958C *)(p + 0x1BA) = 2;
                if (func_021D9320((u8 *)p)) {
                    func_021D9348(p);
                    func_020061E4(1357);
                } else {
                    func_021D8AF4(p, 4);
                }
            } else if (n >= 12 && n <= 21) {
                if (*(int *)(p + 0x240) == 0) return;
                func_020061E4(1356);
                idx = *(int *)(p + 0x188);
                r[idx].state = n - 11;
                func_0204B878(r[idx].handle, func_021DA158(r[idx].state, r[idx].flag));
                func_021D9E48(p, 1, 1);
                m = n - 12;
                func_021D9E98(p, m);
                func_021D9E48(p, 1, 0);
                func_021D9E48(p, 2, 1);
                func_021D9EE8(p, m, 2);
                func_0204B878(*(struct Obj **)(p + 0x1CC), 3);
                v = r[idx].value;
                if (idx + 1 == *(int *)(p + 0x23C)) {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = 0;
                    *(int *)(p + 0x324) = 0;
                } else {
                    k = r[idx + 1].value;
                    if (v != k) {
                        *(int *)(p + 0x31C) = 1;
                        *(int *)(p + 0x320) = k;
                        *(int *)(p + 0x324) = 0;
                    } else {
                        *(int *)(p + 0x31C) = 2;
                        *(int *)(p + 0x320) = idx + 1;
                    }
                }
                func_021D9564((u8 *)p, n);
            } else {
                *(s16_021D958C *)(p + 0x1B8) = (n - 12) % 5;
                *(s16_021D958C *)(p + 0x1BA) = (n - 12) / 5;
            }
        }
    }
}

/*
 * Extent ends with two bytes of zero alignment padding.
 */
void func_021D9760(char *p)  {
    switch(((struct Obj00361 *)p)->f31C)  {
        case 0: break;
        case 1: func_021D8950(p,((struct Obj00361 *)p)->f320);
        func_021DA164(p);
        func_021DA1A8(p,1);
        func_021D8AF4(p,2);
        ((struct Obj00361 *)p)->f31C=255;
        break;
        case 2: func_021D9E60((u8 *)p,((struct Obj00361 *)p)->f320);
        func_021D97B8(p);
        break;
        case 255: break;
    }
}


void func_021D97B8(char *p)
{
    ((struct Obj00361 *)p)->f31C = 0;
    ((struct Obj00361 *)p)->f320 = 0;
    ((struct Obj00361 *)p)->f324 = 0;
}

int func_021D97CC(u8 *p,int value) { int i; int count; count=((struct Obj23117 *)p)->f23C; for(i=0;i<count;i++) if(value==*(int *)(p+i*28+4)) return i; return 0; }
