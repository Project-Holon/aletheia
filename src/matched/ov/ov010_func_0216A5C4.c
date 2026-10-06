/*
 * function: func_0216A5C4
 * address: 0x0216A5C4
 * packet: pkt_ov010_0216A5C4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008E68 0x02008E68 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Big;
struct Ctx;
struct Sub02008C20Obj;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02159B10(void *,void *);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void func_02008E68(struct Sub02008C20Obj *obj, u32 value);
int func_0216A5C4(void *a,void *b) { void *sys; u32 n; func_0215A5F4(b); sys=func_020120F4(func_0215A5DC(b)); n=func_02159B10(a,b); func_02008E68(func_02008C58(func_02012EBC(sys)),(u8)n); return 0; }
