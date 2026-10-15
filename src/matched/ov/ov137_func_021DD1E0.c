/*
 * function: GURU2_RECEIPT_InitBg
 * address: 0x021DD1E0
 * packet: pkt_ov137_021DD1E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_0203FC28 0x0203FC28 arm
 * BG_SYS_InitBgLayer 0x0203FCA0 arm
 * BG_SYS_ClearSlot 0x020414EC arm
 * BG_SYS_InitRun 0x02040B94 arm
 * gGuru2LobbyDispConfig 0x021E1B70 data a4
 * gGuru2LobbyBg0Template 0x021E1BE0 data a4
 * gGuru2LobbyBg1Template 0x021E1B80 data a4
 * gGuru2LobbyBg2Template 0x021E1BA0 data a4
 * gGuru2LobbyBg3Template 0x021E1BC0 data a4
 * gGuru2LobbyBg4Template 0x021E1C00 data a4
 */
typedef unsigned int u32;
struct DispConfig { u32 w[4]; };
struct BgTemplate { u32 w[8]; };
extern const struct DispConfig gGuru2LobbyDispConfig;
extern const struct BgTemplate gGuru2LobbyBg0Template,gGuru2LobbyBg1Template,gGuru2LobbyBg2Template,gGuru2LobbyBg3Template,gGuru2LobbyBg4Template;
extern void func_0203FC28(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
typedef unsigned short u16;
typedef unsigned char  u8;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
void GURU2_RECEIPT_InitBg(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f;
    d=gGuru2LobbyDispConfig;
    func_0203FC28(&d);
    a=gGuru2LobbyBg0Template;
    BG_SYS_InitBgLayer(4,&a,0); BG_SYS_ClearSlot(4);
    b=gGuru2LobbyBg1Template;
    BG_SYS_InitBgLayer(5,&b,0); BG_SYS_ClearSlot(5);
    c=gGuru2LobbyBg2Template;
    BG_SYS_InitBgLayer(6,&c,0); BG_SYS_InitRun(4,32,0,114);
    e=gGuru2LobbyBg3Template;
    BG_SYS_InitBgLayer(0,&e,0); BG_SYS_ClearSlot(0);
    f=gGuru2LobbyBg4Template;
    BG_SYS_InitBgLayer(1,&f,0); BG_SYS_InitRun(0,32,0,114);
}
