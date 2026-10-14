/*
 * function: DENDOU_VIEW_IsMemberLeftOfCenter
 * address: 0x021DD5A8
 * packet: pkt_ov171_021DD5A8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_GetActiveActorBase 0x021DE5F4 thumb ov171
 *   DENDOU_VIEW_GetActorPos 0x021DE0E4 thumb ov171
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {s16 a,b;} Outputs;
extern int DENDOU_VIEW_GetActiveActorBase(char *);
extern void DENDOU_VIEW_GetActorPos(u8 *,int,s16 *,s16 *);
int DENDOU_VIEW_IsMemberLeftOfCenter(u8 *p,int i)
{
    Outputs out;
    DENDOU_VIEW_GetActorPos(p,(int)((u32)i+(u32)DENDOU_VIEW_GetActiveActorBase((char *)p)), &out.b, &out.a);
    if(out.b<128)return 1;
    return 0;
}
