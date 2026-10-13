/*
 * function: FIELD_WFBC_BLOCK_InitRand
 * address:  0x02194084
 * packet:   pkt_ov021_02194084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_LoadNpcData  0x02186818  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb  ov020
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef unsigned long long u64;
typedef struct { u8 x0; u8 x1; u8 pad[22]; } Item;
typedef struct { u32 x0; u32 x4; Item items[10]; } In;
typedef struct {
    u64 seed;
    u64 mul;
    u64 add;
    u16 x18;
    u16 x1a;
    u32 x1c;
    u32 x20;
} Out;
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(Item *);
extern void FIELD_WFBC_DATA_LOCAL_LoadNpcData(u32 *p, u32 member);
extern char *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(char *p);
extern int FIELD_WFBC_DATA_LOCAL_CountPeople(char *p, int which);

void FIELD_WFBC_BLOCK_InitRand(Out *o, In *in, u32 c)
{
    int sum;
    int cnt;
    int i;

    sum = 0;
    cnt = 0;
    for (i = 0; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&in->items[i]) != 0) {
            FIELD_WFBC_DATA_LOCAL_LoadNpcData((u32 *)c, in->items[i].x1);
            sum += *(u16 *)(FIELD_WFBC_DATA_LOCAL_GetNpcRecord((char *)c) + 0x2E);
            cnt += in->items[i].x1;
        }
    }
    o->x1c = FIELD_WFBC_DATA_LOCAL_CountPeople((char *)in, 0);
    o->seed = in->x4;
    o->mul = 0x5D588B656C078965ULL;
    o->add = 0x269EC3;
    if (o->x1c == 0) {
        o->x18 = 1;
    } else {
        o->x18 = sum + 2;
    }
    o->x1a = cnt;
    o->x20 = in->x4;
}
