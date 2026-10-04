/*
 * function: func_02164FD0
 * address:  0x02164FD0
 * packet:   pkt_ov010_02164FD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 6-byte record out of the object, and when no flag / busy
 * checks trip allocates a 0x10-byte record holding it and registers it.
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   func_02012138  0x02012138  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02012164  0x02012164  thumb
 *   func_020264AC  0x020264AC  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_02026454  0x02026454  thumb
 *   func_02030734  0x02030734  arm
 *   func_020263D8  0x020263D8  thumb
 *   d_021729BC     0x021729BC  data  ov010  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_02082D44(void *src, void *dst, int n);
struct Ctx;
extern u32   func_02012138(const struct Ctx *p);
extern void  func_020307B0(void *a);
struct Comm;
struct IcaAnime;
extern u32 func_02012164(struct IcaAnime *p);
extern u32 func_020264AC(void *obj);
extern int   func_0203CD98(void);
extern u32 func_02026454(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern const char d_021729BC[];

void func_02164FD0(u8 *obj, int flag)
{
    u8 buf[6];
    u32 o = *(u32 *)obj;
    u32 w;
    u8 *p;
    func_02082D44(obj + 4, buf, 6);
    w = func_02012138((const struct Ctx *)o);
    func_020307B0(obj);
    if (flag == 0 && func_02012164((struct IcaAnime *)o) == 1 && func_020264AC((void *)w) == 0
        && func_0203CD98() == 0 && func_02026454((void *)w) == 0) {
        p = func_02030734(5, 0x10, 1, d_021729BC, 0x287);
        *(u32 *)p = o;
        *(u32 *)(p + 4) = func_02012138((const struct Ctx *)o);
        func_02082D44(buf, p + 8, 6);
        func_020263D8((struct Comm *)w, 2, (u32)p);
    }
}
