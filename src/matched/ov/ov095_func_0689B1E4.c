/*
 * function: func_0689B1E4
 * address: 0x0689B1E4
 * packet: pkt_ov095_0689B1E4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0689B2E4 0x0689B2E4 thumb ov095
 *   func_0689B2F4 0x0689B2F4 thumb ov095
 *   func_0689B304 0x0689B304 thumb ov095
 *   func_0689B314 0x0689B314 thumb ov095
 *   func_0689B324 0x0689B324 thumb ov095
 *   func_0689B334 0x0689B334 thumb ov095
 *   func_0689ADDC 0x0689ADDC thumb ov095
 *   func_0689B344 0x0689B344 thumb ov095
 *   d_0689E5D8 0x0689E5D8 data a4
 *   d_0689E560 0x0689E560 data a4
 *   d_0689E650 0x0689E650 data a4
 *   d_0689E704 0x0689E704 data a4
 */
#include "../include/Obj01913.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 kind:7, id:16, rest:9; } Q;
typedef struct { u8 n, pad[2], d[16]; } St;
extern const char *const d_0689E5D8[][15], *const d_0689E560[][15], *const d_0689E650[][15], *const d_0689E704[][15];
extern u8 func_0689B2E4(void *);
extern int func_0689B2F4(void *, void *, u32);
extern u8 func_0689B304(void *, u32);
extern u32 func_0689B314(void *);
extern u32 func_0689B324(u16, u32);
extern int func_0689B334(char *, const char *, int);
extern int func_0689ADDC(St *, int, u32, u8 *);
extern void func_0689B344(Q *, u16, u8);
int func_0689B1E4(int *state, u8 *s)
{
    u8 i, row, out;
    int mode, stop, idx;
    const char *q, *r;
    if (*state == 0) {
    mode = func_0689B304(((struct Obj01913 *)s)->fA0, func_0689B2F4(((struct Obj01913 *)s)->fA0, ((struct Obj01913 *)s)->fA4, func_0689B2E4(((struct Obj01913 *)s)->f6C)));
    i = s[0x8a];
    row = (mode - 2) / 2;
    if (func_0689B314(((struct Obj01913 *)s)->fA0) != 2) {
        q = d_0689E5D8[row][i];
        r = d_0689E560[row][i];
        stop = 4;
    } else {
        if (i == 0 && func_0689B324((*(Q * *)&((struct Obj01913 *)s)->f70)->id, 0xb)) i = 14;
        q = d_0689E650[row][i];
        r = d_0689E704[row][i];
        stop = 6;
    }
    idx = func_0689B334(*(char * *)&((struct Obj01913 *)s)->fB0, q, (int)r);
    if (idx != -1) {
        if (idx != stop) {
            if (func_0689ADDC((St *)(s + 0x80), idx, *(u32 *)&((struct Obj01913 *)s)->fA0, &out)) {
                func_0689B344(*(Q * *)&((struct Obj01913 *)s)->f70, (*(Q * *)&((struct Obj01913 *)s)->f70)->id, out);
                s[0x89] = 1;
                return 1;
            }
        } else {
            s[0x89] = 0;
            return 1;
        }
    }
    }
    return 0;
}
