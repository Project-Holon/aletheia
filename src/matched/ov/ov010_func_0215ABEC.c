/*
 * function: SCRCMD_WORK_CmdGetBirthday
 * address: 0x0215ABEC
 * packet: pkt_ov010_0215ABEC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: compiled 46 bytes; trailing 0x0215AC1A..0x0215AC1C is zero alignment.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   OS_GetOwnerInfoEx 0x02087D28 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Info { u8 language, color, month, day; u16 name[11], nameLength, comment[27], commentLength; u8 country, padding; } Info;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct OSOwnerInfoEx;
extern void OS_GetOwnerInfoEx(struct OSOwnerInfoEx *info);
int SCRCMD_WORK_CmdGetBirthday(int a, int b) {
 u16 *p, *q;
 Info info;
 p = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
 q = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
 OS_GetOwnerInfoEx((struct OSOwnerInfoEx *)(&info));
 *p = info.month;
 *q = info.day;
 return 0;
}
