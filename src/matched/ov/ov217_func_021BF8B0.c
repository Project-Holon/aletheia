/*
 * function: RESEARCH_GRAPH_GetFirstSaveGroup
 * address: 0x021BF8B0
 * packet: pkt_ov217_021BF8B0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pointer-typed lookup base keeps the original r4/r5 allocation; E44C full body reads only r0/r1 and forwards neither legacy trailing input.
 * F740 tail-forwards to C09B4's pointer getter; E394 tail-forwards to 071CC's returned save block.
 * E44C's full body reads only r0/r1 and has no forwarding calls; legacy two trailing inputs omitted.
 * symbols:
 *   RESEARCH_GRAPH_GetAppResource 0x021BF740 thumb ov217
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   MISC_SAVEDATA_GetStatusByte 0x0200E44C thumb
 *   d_021C363C 0x021C363C data ov217 a1
 *   d_021C3646 0x021C3646 data ov217 a1
 *   d_021C3632 0x021C3632 data ov217 a1
 */
typedef unsigned char u8;
struct Big;
typedef unsigned int   u32;
extern u32 RESEARCH_GRAPH_GetAppResource(u8 *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern int MISC_SAVEDATA_GetStatusByte(int,int);
extern const u8 d_021C363C[];
extern const u8 d_021C3646[];
extern const u8 d_021C3632[];
u8 RESEARCH_GRAPH_GetFirstSaveGroup(u8 *p)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource(p)));
    for (i=0;i<3;i++) bytes[i]=MISC_SAVEDATA_GetStatusByte((int)base,i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}
