/*
 * file:     unit_0689831C.c
 * unit:     yes
 * function: func_0689831C, func_06898328
 * address:  0x0689831C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 *   d_0689D698 0x0689D698 data ov095 a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u8 pad[0x10];
    u32 w6;
} D;

typedef struct {
    u8 pad0[4];
    u16 h4;
    u8 b6;
    u8 pad7;
    u8 f8[1];
} M;

extern int BTL_EVENT_GetVar(int k);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(int b);
extern u32 BTL_SERVER_FLOW_GetTurnCount(int b);
extern int BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(int b, int c);
extern int BTL_SERVER_FLOW_GetPokeParam();
extern int BTL_POKEPARAM_IsHpFull(int x);
extern M *BTL_SERVER_FLOW_AllocCmdRecord(int b, int n, int k);
extern u16 BTL_CALC_DivideMaxHpMin1(int x, int n);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int n, int v);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *p, int k);
extern void BTL_SERVER_FLOW_CommitCmdRecord(int b, void *p);
extern void BTL_EVENT_RemoveFactor(int a);
unsigned int *func_0689831C(unsigned int *p);
void func_06898328(int a, int b, int c, D *d);
extern unsigned int d_0689D698;

/*
 * note: Unlabelled follower after the 0689830C veneer; ends before existing 06898328.
 */
unsigned int *func_0689831C(unsigned int *p)
{
    *p = 1;
    return &d_0689D698;
}


void func_06898328(int a, int b, int c, D *d)
{
    if (BTL_EVENT_GetVar(2) == 0x1f && BTL_SERVER_FLOW_CheckShowdownThunk(b) == 0) {
        if (d->w0 == 0) {
            d->w1 = BTL_SERVER_FLOW_GetTurnCount(b);
            d->w0 = 1;
        } else if (BTL_SERVER_FLOW_GetTurnCount(b) > d->w1) {
            int s = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(b, c);

            if (s != 0x1f) {
                if (BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(b, s)) == 0) {
                    u8 k = d->w6;
                    int t = BTL_SERVER_FLOW_GetPokeParam(b, k);
                    M *m = BTL_SERVER_FLOW_AllocCmdRecord(b, 5, k);

                    m->b6 = s;
                    m->h4 = BTL_CALC_DivideMaxHpMin1(t, 2);
                    BTL_SERVER_FLOW_InitMsgRecord(m->f8, 2, 0x2bc);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(m->f8, k);
                    BTL_SERVER_FLOW_CommitCmdRecord(b, m);
                }
            }
            BTL_EVENT_RemoveFactor(a);
        }
    }
}
