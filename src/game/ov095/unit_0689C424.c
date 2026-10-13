/*
 * file:     unit_0689C424.c
 * unit:     yes
 * function: func_0689C424, func_0689C464
 * address:  0x0689C424
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
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb
 *   d_0689E21C   0x0689E21C  data  ov095  a4
 */
typedef unsigned int u32;

typedef short s16;

typedef struct Ent {
    u32 key;
    s16 a;
    s16 b;
} Ent;

typedef unsigned short u16;

typedef struct Word { int v; } Word;

extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, u16);
extern int BTL_POKEPARAM_GetPokeId(void *);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *, int);
extern int BTLV_CORE_GetSlotValue(Word);
int func_0689C424(u32 key, int flag);
int func_0689C464(int a, Word b, void *c, unsigned char d, void *e);
extern Ent d_0689E21C[17];


int func_0689C424(u32 key, int flag)
{
    u32 i;
    int v;

    for (i = 0; i < 17; i++) {
        if (key == d_0689E21C[i].key) {
            if (flag != 0)
                v = d_0689E21C[i].b;
            else
                v = d_0689E21C[i].a;
            if (v < 0)
                return d_0689E21C[i].a;
            return v;
        }
    }
    return -1;
}


int func_0689C464(int a, Word b, void *c, unsigned char d, void *e)
{
    int f;
    int k;

    f = 1;
    if (d == 0)
        f = 0;
    k = func_0689C424(a, f);
    if (k >= 0) {
        BTL_SERVER_FLOW_InitMsgRecord(e, 2, k);
        BTL_SERVER_FLOW_AppendMsgRecordArg(e, BTL_POKEPARAM_GetPokeId(c));
        if (f != 0)
            BTL_SERVER_FLOW_AppendMsgRecordArg(e, d);
        switch (a) {
        case 8:
            BTL_SERVER_FLOW_AppendMsgRecordArg(e, BTLV_CORE_GetSlotValue(b));
            break;
        case 0x12:
            BTL_SERVER_FLOW_AppendMsgRecordArg(e, 0x49);
            break;
        }
        return 1;
    }
    return 0;
}
