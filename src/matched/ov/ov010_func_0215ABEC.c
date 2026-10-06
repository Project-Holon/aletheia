/*
 * function: func_0215ABEC
 * address: 0x0215ABEC
 * packet: pkt_ov010_0215ABEC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: compiled 46 bytes; trailing 0x0215AC1A..0x0215AC1C is zero alignment.
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02087D28 0x02087D28 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Info { u8 language, color, month, day; u16 name[11], nameLength, comment[27], commentLength; u8 country, padding; } Info;
extern u16 *func_02159AE8(void *a0, void *a1);
struct OSOwnerInfoEx;
extern void func_02087D28(struct OSOwnerInfoEx *info);
int func_0215ABEC(int a, int b) {
 u16 *p, *q;
 Info info;
 p = func_02159AE8((void *)a, (void *)b);
 q = func_02159AE8((void *)a, (void *)b);
 func_02087D28((struct OSOwnerInfoEx *)(&info));
 *p = info.month;
 *q = info.day;
 return 0;
}
