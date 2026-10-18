/*
 * function: CTVT_COMM_ReceiveVoicePacket
 * address: 0x021B8978
 * packet: pkt_ov172_021B8978
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_TVT_SYS_GetTalkStatus 0x021BDFEC thumb ov172
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   CTVT_ADPCM_ResetDecoder 0x021B69F0 thumb ov172
 *   MIi_CpuClear32 0x02082A7C arm
 *   CTVT_MIC_DecodeAdpcm 0x021BA194 thumb ov172
 *   gCtvtCommFreqTable 0x021C6EC0 data a2
 */
#include "../include/Obj03854.h"
#include "../include/Obj05444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 a[9]; } Table;
extern const Table gCtvtCommFreqTable;
extern int COMM_TVT_SYS_GetTalkStatus(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void CTVT_ADPCM_ResetDecoder(void);
extern void MIi_CpuClear32(int, void *, int);
extern int CTVT_MIC_DecodeAdpcm(int unused, int a, void *buf, unsigned n);
void CTVT_COMM_ReceiveVoicePacket(int a, int b, int c, char *q)
{
    void *p;
    char *data, *input;
    Table table;
    p = (void *)COMM_TVT_SYS_GetTalkStatus(((struct Obj03854 *)q)->f3DC);
    data = *(char * *)&((struct Obj03854 *)q)->f1A4;
    input = data + 8;
    GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    if (((struct Obj05444 *)data)->f5 == 0) {
        CTVT_ADPCM_ResetDecoder();
        MIi_CpuClear32(0, ((struct Obj03854 *)q)->f1A8, 0xc800);
    }
    CTVT_MIC_DecodeAdpcm((int)p, (int)input, *(char * *)&((struct Obj03854 *)q)->f1A8 + (((struct Obj05444 *)data)->f5 << 11), ((struct Obj05444 *)data)->f0);
    if (((struct Obj05444 *)data)->f4 == 1) {
        table = gCtvtCommFreqTable;
        ((struct Obj03854 *)q)->f1A0 = table.a[((struct Obj05444 *)data)->f6];
        ((struct Obj03854 *)q)->f198 = 1;
        ((struct Obj03854 *)q)->f19C = ((struct Obj05444 *)data)->f2;
    }
    ((struct Obj03854 *)q)->f194 = 0;
}
