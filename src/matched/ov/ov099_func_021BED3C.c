/*
 * function: func_021BED3C
 * address: 0x021BED3C
 * packet: pkt_ov099_021BED3C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_02009A34 0x02009A34 thumb
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 */

typedef unsigned int u32;
extern u32 func_020362DC(void);
struct Sub020097BCObj;
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void func_021BAAB8(char *, int, int);
extern void func_021BE6F0(char *, int, int);
extern int func_021BE788(char *);
extern int func_021BE4F0(char *, int);
extern int func_021BA8BC(void *p);
int func_021BED3C(char *p, int ret)
{
    if (func_020362DC() & 3) {
        if (!func_02009A34(*(void **)(p + 4))) {
            func_021BAAB8(p, 0x1a, 1);
            *(int *)(p + 0x1cc) = 0x33;
            *(int *)(p + 0x1e0) = 1;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
            *(void **)(p + 0x19c) = (void *)func_021BA8BC(*(void **)(p + 0x19c));
        }
    }
    return ret;
}
