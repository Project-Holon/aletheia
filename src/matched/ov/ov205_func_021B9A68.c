/*
 * function: func_021B9A68
 * address: 0x021B9A68
 * packet: pkt_ov205_021B9A68
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021B9A92 follow; no follower.
 * symbols:
 *   func_02088864 0x02088864 arm
 *   func_02012934 0x02012934 thumb
 *   func_02012F68 0x02012F68 thumb
 *   func_0200EA3C 0x0200EA3C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec; struct BigObj; struct Date; extern void func_02088864(void *); extern void *func_02012934(const struct BigObj *);extern void *func_02012F68(void **);extern void func_0200EA3C(struct Rec *,void *,struct Date *,u32);
void func_021B9A68(char *p) { u32 date[4];void *party,*rec;func_02088864(date);party=func_02012934(*(struct BigObj **)(p+4));rec=func_02012F68(*(void ***)(p+4));func_0200EA3C(rec,party,(struct Date *)date,4); }
