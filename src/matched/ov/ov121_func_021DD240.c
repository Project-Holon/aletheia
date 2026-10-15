/*
 * function: MYSTERY_ALBUM_UpdateSlotWork
 * address: 0x021DD240
 * packet: pkt_ov121_021DD240
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_IsWindowListDone 0x021DA2C8 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_UTIL_IsWindowListDone(u8 *p);
int MYSTERY_ALBUM_UpdateSlotWork(void **p) {return MYSTERY_UTIL_IsWindowListDone(*p);}
