/*
 * function: func_021B9C9C
 * address: 0x021B9C9C
 * packet: pkt_ov172_021B9C9C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021B80E4 0x021B80E4 thumb ov172
 *   func_021BE0A4 0x021BE0A4 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021B9C1C 0x021B9C1C thumb ov172
 *   func_021BE11C 0x021BE11C thumb ov172
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021BDFE4(void *);
extern u32 func_021B80E4(int, char *);
extern u8 func_021BE0A4(void *);
extern u8 func_021BE054(void *);
extern void func_021B9C1C(void *p, char *q, int id);
extern u32 func_021BE11C(u8 *p);
struct Actor;
struct Obj;
typedef unsigned short u16;
extern u32 func_0204B98C(struct Actor *);
extern void func_0204B878(struct Obj *, u16);
void func_021B9C9C(void *p, char *q)
{
    if (func_021B80E4((int)p, (char *)func_021BDFE4(p)) == 5) {
        func_021B9C1C(p, q, 32);
    } else if (func_021BE0A4(p) == 0 && func_021BE054(p) > 1) {
        func_021B9C1C(p, q, 33);
    } else {
        func_021B9C1C(p, q, 32);
    }
    *(void **)(q + 128) = (void *)func_021BE11C(p);
    *(u32 *)q = 10;
    if (func_0204B98C(*(void **)(q + 152)) == 0)
        func_0204B878(*(void **)(q + 152), 15);
}
