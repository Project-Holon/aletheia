/*
 * function: SCRCMD_PROC_ChangeMonFriendship
 * address:  0x0215B74C
 * packet:   pkt_ov010_0215B74C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
int SCRCMD_PROC_ChangeMonFriendship(int a0, int a1)
{
    int a = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int b = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int mode = VM_GetU16((struct Stream *)a0);
    int obj = 0;
    u8 v;
    if (SCRCMD_PROC_GetPartyMember((void *)a1, a, (void **)(&obj)) == 0) {
        return 0;
    }
    if (POKE_TOOL_GetPartyValue((void *)obj, 0x4C, 0) == 1) {
        return 0;
    }
    v = POKE_TOOL_GetPartyValue((void *)obj, 9, 0);
    switch (mode) {
    case 0:
        if ((u32)b > 0xFF) {
            v = 0xFF;
        } else {
            v = b;
        }
        break;
    case 1:
        if (v + b > 0xFF) {
            v = 0xFF;
        } else {
            v = v + (u8)b;
        }
        break;
    case 2:
        if (v < b) {
            v = 0;
        } else {
            v = v - (u8)b;
        }
        break;
    }
    POKE_TOOL_SetPartyValue((void *)obj, 9, v);
    return 0;
}
