/*
 * function: func_0218E18C
 * address:  0x0218E18C
 * packet:   pkt_ov021_0218E18C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218E260  0x0218E260  thumb ov021
 *   func_0218EC7C  0x0218EC7C  thumb ov021
 *   func_0218EC68  0x0218EC68  thumb ov021
 *   func_02046BE0  0x02046BE0  arm
 *   func_02048B78  0x02048B78  arm
 *   func_02048B80  0x02048B80  arm
 *   func_02048B94  0x02048B94  arm
 *   tbl_020A1B38   0x020A1B38  data
 */
#include "../include/Obj01347.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    u8 e;
    u8 mode;
    u16 ang;
    int f;
    int g;
    int has;
    Vec v;
} Info;

extern void func_0218E260(void *p, void *dst);
extern void func_0218EC7C(char *p, int a);
extern void func_0218EC68(char *p, int a);
typedef unsigned int   u32;
extern void func_02046BE0(u32 a, u32 b);
struct Light;
extern int func_02048B78(struct Light *l);
extern void func_02048B80(int a, int v);
extern void func_02048B94(int a, int v);
extern s16 tbl_020A1B38[];

void func_0218E18C(char *p, Vec *src)
{
    Info info;

    func_0218E260(p, &info);
    ((struct Obj01347 *)p)->f7C = info.a << 12;
    ((struct Obj01347 *)p)->f78 = info.b;
    ((struct Obj01347 *)p)->f7A = info.c;
    ((struct Obj01347 *)p)->f80 = info.ang;
    func_0218EC7C(p, info.g);
    func_0218EC68(p, info.f);
    switch (info.mode) {
    case 0:
        func_02046BE0(0, 0);
        break;
    case 1:
        func_02046BE0(0, 1);
        break;
    }
    if (func_02048B78((struct Light *)(((struct Obj01347 *)p)->fC)) == 0) {
        func_02048B80(((struct Obj01347 *)p)->fC, tbl_020A1B38[(((struct Obj01347 *)p)->f80 >> 4) * 2]);
        func_02048B94(((struct Obj01347 *)p)->fC, tbl_020A1B38[(((struct Obj01347 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (info.has != 0) {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = src;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = src;
        *(Vec *)(p + 0x48) = *src;
        *(Vec *)(p + 0x60) = info.v;
    } else {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = 0;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = 0;
        *(Vec *)(p + 0x48) = info.v;
        ((Vec *)(p + 0x60))->x = 0;
        ((Vec *)(p + 0x60))->y = 0;
        ((Vec *)(p + 0x60))->z = 0;
    }
}
