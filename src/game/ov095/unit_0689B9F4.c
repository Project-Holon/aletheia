/*
 * file:     unit_0689B9F4.c
 * function: func_0689B9F4
 * address: 0x0689B9F4
 * packet: pkt_ov095_0689B9F4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: inline Slot-to-Word reinterpretation preserves the extra aggregate home word; passing the aggregate directly differed only at the four frame bytes.
 * symbols:
 *   BTL_SERVER_FLOW_GetPosTableEntryForPoke  0x021C7D44  thumb
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   func_021D59B4  0x021D59B4  thumb
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef union {
    struct { u32 kind:3, pad:6, id:16, rest:7; } a;
    struct { u32 kind:3, pad:12, id:16, rest:1; } b;
} Word;
typedef struct { u32 kind:3, rest:29; } Slot;
typedef struct { u32 flags; u16 hp; u8 c, bits; u16 msg; u8 id, slot; u8 data[1]; } Rec;
extern Slot BTL_POKEPARAM_GetSickContRaw(void *, int);
extern u16 BTLV_CORE_GetSlotValue(Word);
extern int BTL_SERVER_FLOW_GetPosTableEntryForPoke(char *p, u8 i);
extern int BTL_CALC_DivideMaxHpMin1(void *, u32);
extern int func_021D59B4(void *, int);
extern Rec *BTL_SERVER_FLOW_AllocCmdRecord(void *, int, int);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *, u32);
extern int BTL_SERVER_FLOW_GetPokeViewPos(void *, int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
static inline u16 decode(Slot s)
{
    return BTLV_CORE_GetSlotValue(*(Word *)&s);
}
void func_0689B9F4(void *a, void *b, int c)
{
    u8 id;
    int x;
    u16 hp, max;
    Rec *r;
    int msg;
    id = (u8)decode(BTL_POKEPARAM_GetSickContRaw(b, 0x12));
    x = BTL_SERVER_FLOW_GetPosTableEntryForPoke(a, id);
    if (x == 0x1f) return;
    hp = BTL_CALC_DivideMaxHpMin1(b, 8);
    max = func_021D59B4(b, 0xd);
    if (hp > max) hp = max;
    r = BTL_SERVER_FLOW_AllocCmdRecord(a, 7, c);
    r->c = c;
    r->hp = hp;
    msg = 0x262;
    BTL_SERVER_FLOW_InitMsgRecord(r->data, 2, msg);
    BTL_SERVER_FLOW_AppendMsgRecordArg(r->data, c);
    r->bits |= 2;
    msg += 0x13;
    r->msg = msg;
    r->id = id;
    r->slot = BTL_SERVER_FLOW_GetPokeViewPos(a, c);
    BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    if (x != 0x1f) {
        r = BTL_SERVER_FLOW_AllocCmdRecord(a, 6, c);
        r->flags |= 0x1000000;
        r->c = x;
        r->bits = c;
        r->hp = hp;
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
