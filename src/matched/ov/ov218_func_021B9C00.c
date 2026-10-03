/*
 * function: func_021B9C00
 * address: 0x021B9C00
 * packet: pkt_ov218_021B9C00
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_020061E4 0x020061E4 thumb
 * Original consumes r0 from the legacy void 35C38/35C60 wrappers;
 * their final forwarding targets 357A0/357C0 return a halfword load.
 */

typedef unsigned int u32;
struct Rec3;
struct Rec;
extern unsigned int func_0201CE30(void *);
extern void func_0201CE48(struct Rec3 *);
extern void func_0201CE38(void *);
extern void func_0201CE5C(struct Rec *, int);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern unsigned int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4(unsigned int);
int func_021B9C00(char *p)
{
    if (*(void **)(p + 32) != 0) {
        switch (func_0201CE30(*(void **)(p + 32))) {
        case 2:
            func_0201CE48(*(struct Rec3 **)(p + 32));
            *(void **)(p + 32) = 0;
            return 1;
        case 1:
            if (func_020362DC() == 1 || func_020362DC() == 2 || func_02035C60() != 0) {
                func_0201CE38(*(void **)(p + 32));
                func_020061E4(1356);
            }
            break;
        case 0:
            if (((unsigned int)func_0203630C() & 3) != 0 || func_02035C38() != 0)
                func_0201CE5C(*(struct Rec **)(p + 32), 0);
            break;
        }
        return 0;
    }
    return 0;
}
