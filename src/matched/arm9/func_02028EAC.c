/*
 * Byte-correct, MATCH*-capped. NOT in the manifest; see src/pending/README.md.
 *
 * function: FIELD_SOUND_SYSTEM_ExecuteRequest
 * address:  0x02028EAC
 * packet:   pkt_02028DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker FIELD_SOUND_SYSTEM_ProcessNextRequest.c is now a manifest entry (matched class)
 * symbols:
 *   FIELD_SOUND_SYSTEM_SetMode1  0x02028F18  thumb
 *   FIELD_SOUND_SYSTEM_SetMode2  0x02028F30  thumb
 *   FIELD_SOUND_SYSTEM_SetMode3  0x02028F48  thumb
 *   FIELD_SOUND_SYSTEM_SetMode4  0x02028F60  thumb
 *   FIELD_SOUND_SYSTEM_SetMode5  0x02028F7C  thumb
 *   FIELD_SOUND_SYSTEM_SetMode6  0x02028F9C  thumb
 *   FIELD_SOUND_SYSTEM_SetMode7  0x02028FB8  thumb
 *
 * Previously blocked at MATCH* on callees: FIELD_SOUND_SYSTEM_SetMode2 through FIELD_SOUND_SYSTEM_SetMode7 reside in
 * unit_02028F18 (pkt_02028B50), but unit_02028F18's header only lists FIELD_SOUND_SYSTEM_SetMode1,
 * so the other internal functions have no external branch witness in the manifest.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct SoundParam2;

extern void FIELD_SOUND_SYSTEM_SetMode1(struct SoundParam2 *obj, u16 a1);
extern void FIELD_SOUND_SYSTEM_SetMode2(u8 *p, u32 a);
extern void FIELD_SOUND_SYSTEM_SetMode3(u8 *p, u32 a);
extern void FIELD_SOUND_SYSTEM_SetMode4(u8 *p, u32 a, u32 b);
extern void FIELD_SOUND_SYSTEM_SetMode5(u8 *p, u32 a, u32 b, u32 c);
extern void FIELD_SOUND_SYSTEM_SetMode6(u8 *p, u32 a, u32 b);
extern void FIELD_SOUND_SYSTEM_SetMode7(u8 *p, u32 a);

void FIELD_SOUND_SYSTEM_ExecuteRequest(struct SoundParam2 *obj, struct Cmd *cmd)
{
    switch (cmd->unk00) {
    case 1:
        FIELD_SOUND_SYSTEM_SetMode1(obj, cmd->unk0A);
        break;
    case 2:
        FIELD_SOUND_SYSTEM_SetMode2((u8 *)obj, cmd->unk08);
        break;
    case 3:
        FIELD_SOUND_SYSTEM_SetMode3((u8 *)obj, cmd->unk08);
        break;
    case 4:
        FIELD_SOUND_SYSTEM_SetMode4((u8 *)obj, cmd->unk08, cmd->unk0A);
        break;
    case 5:
        FIELD_SOUND_SYSTEM_SetMode5((u8 *)obj, cmd->unk04, cmd->unk08, cmd->unk0A);
        break;
    case 6:
        FIELD_SOUND_SYSTEM_SetMode6((u8 *)obj, cmd->unk04, cmd->unk08);
        break;
    case 7:
        FIELD_SOUND_SYSTEM_SetMode7((u8 *)obj, (u16)cmd->unk04);
        break;
    default:
        break;
    }
}
