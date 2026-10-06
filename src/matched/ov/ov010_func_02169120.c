/*
 * function: func_02169120
 * address: 0x02169120
 * packet: pkt_ov010_02169120
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008B14 0x02008B14 thumb
 *   func_0203F524 0x0203F524 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Big;
extern void *func_02012EBC(struct Big *p);
struct Sub02008AECSession;
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern u64 func_0203F524(void);
void func_02169120(void *p) { char *q = (char *)func_02008B14(func_02012EBC(p)); *(u64 *)(q + 0x2c) = func_0203F524(); }
