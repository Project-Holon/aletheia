/*
 * function: func_02169068
 * address: 0x02169068
 * packet: pkt_ov010_02169068
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * interface: final u16 argument follows the original lsls/lsrs #16 pair.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_0216A2EC 0x0216A2EC thumb ov010
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3C0 0x0200C3C0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct BigObj;
extern void *func_02012EBC(struct Big *p);
extern void *func_0201AD0C(void *sys);
extern u8 func_02012984(const struct BigObj *p);
extern int func_0216A2EC(int,int,int,int *,int);
extern void *func_0200C0F0(void *sys);
extern void func_0200C3C0(int,u16);
void func_02169068(int a,int b,int *c) { int t=(int)func_0201AD0C(func_02012EBC((struct Big *)a)); func_0216A2EC(a,t,b,c,func_02012984((const struct BigObj *)a)); func_0200C3C0((int)func_0200C0F0(func_02012EBC((struct Big *)a)),b); }
