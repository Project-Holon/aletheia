/*
 * function: func_02051B84
 * address:  0x02051B84
 * packet:   pkt_02051B84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02030734   0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02051C58   0x02051C58  arm
 *   g_020A7FCC      0x020A7FCC  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u16 id, u32 size, u32 flags, void *file, u32 line);
extern u32 func_020307B0(void *p);
extern void func_02051C58(void *p);
extern int g_020A7FCC;

typedef struct S02051B84 {
    u8 *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
} S02051B84;

void *func_02051B84(u8 *a0, int a1, int a2, int a3)
{
    S02051B84 *r;
    int i = 0;
    unsigned j;

    while (i < 0xff) {
        if (a0[i * 4] == 0xff) {
            break;
        }
        i++;
    }
    r = (S02051B84 *)func_02030734((u16)a3, 0x14, 0, &g_020A7FCC, 0x6b);
    if (r != 0) {
        r->f00 = a0;
        r->f04 = i;
        r->f08 = a1;
        r->f0c = a2;
        r->f10 = (int)func_02030734((u16)a3, i * 4, 0, &g_020A7FCC, 0x73);
        if (r->f10 != 0) {
            for (j = 0; j < i; j++) {
                func_02051C58((void *)(r->f10 + j * 4));
            }
        } else {
            func_020307B0(r);
            r = 0;
        }
    }
    return r;
}
