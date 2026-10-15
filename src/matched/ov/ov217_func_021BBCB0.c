/*
 * function: RESEARCH_LIST_StoreSaveValues
 * address: 0x021BBCB0
 * packet: pkt_ov217_021BBCB0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status:   EXACT
 * blocker: needs the arm9 0200E440 shard (src/matched/arm9/SYMBOL_SAVE_SetBitDescriptor.c filed 2026-10-02 by wC1 lane02, no shard yet); integrator re-verifies after manifest, then moves this to matched.
 * blocker C: typedef unsigned char u8; void SYMBOL_SAVE_SetBitDescriptor(u8 *p,int value,int index) { (p+index)[640]=value; }
 * arity: BC628 returns C09B4's +8 pointer; E394 returns 071CC's pointer, both used live despite legacy void declarations.
 * symbols:
 *   RESEARCH_LIST_GetSelectedIndex 0x021BC6E4 thumb ov217
 *   RESEARCH_LIST_GetAppResource 0x021BC628 thumb ov217
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   SYMBOL_SAVE_SetBitDescriptor 0x0200E440 thumb
 *   d_021C30A8 0x021C30A8 data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C308A 0x021C308A data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Big;
extern u32 RESEARCH_LIST_GetSelectedIndex(void *p);
extern u32 RESEARCH_LIST_GetAppResource(u8 *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern void SYMBOL_SAVE_SetBitDescriptor(u8 *p, int value, int index);
extern const u8 d_021C30A8[],d_021C3080[],d_021C308A[];
void RESEARCH_LIST_StoreSaveValues(u8 *p)
{
    u32 index;
    int data;
    index=RESEARCH_LIST_GetSelectedIndex(p);
    data=(int)SYMBOL_SAVE_GetBitBlock((void *)((int)GAME_DATA_GetSaveControl((struct Big *)RESEARCH_LIST_GetAppResource(p))));
    SYMBOL_SAVE_SetBitDescriptor((u8 *)data,d_021C30A8[index],0);
    SYMBOL_SAVE_SetBitDescriptor((u8 *)data,d_021C3080[index],1);
    SYMBOL_SAVE_SetBitDescriptor((u8 *)data,d_021C308A[index],2);
}
