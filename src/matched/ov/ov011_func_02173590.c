/*
 * function: INTRUDE_COMM_InitBeacon
 * address:  0x02173590
 * packet:   pkt_ov011_02173590
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =MI_CpuCopy8; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */

typedef unsigned char u8;

typedef struct {
    u8 kind;
    u8 a : 4;
    u8 b : 4;
    u8 c : 1;
    u8 d : 5;
    u8 e : 2;
} Hdr;

extern int GFL_NET_GetNegotiationNum(void);
typedef unsigned int   u32;
extern u32 GFL_NET_SYSTEM_CheckError(void);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *src, void *dst);

void INTRUDE_COMM_InitBeacon(int a, Hdr *p, int c)
{
    p->kind = 2;
    p->a = GFL_NET_GetNegotiationNum();
    if (c != -1)
        p->b = c;
    p->c = GFL_NET_SYSTEM_CheckError();
    p->d = 1;
    MYSTATUS_Copy(GAME_DATA_GetMyStatus((void *)a), (char *)p + 8);
}
