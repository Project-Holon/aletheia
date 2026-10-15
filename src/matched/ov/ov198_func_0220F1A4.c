/*
 * function: B_PLIST_MAIN_UpdateActorAnims
 * address: 0x0220F1A4
 * packet: pkt_ov198_0220F1A4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_GetMonAnimState 0x0220F158 thumb ov198
 *   B_PLIST_MAIN_SetActorAnimSeq 0x0220F138 thumb ov198
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern int B_PLIST_MAIN_GetMonAnimState(char *);
extern void B_PLIST_MAIN_SetActorAnimSeq(void *,int);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
void B_PLIST_MAIN_UpdateActorAnims(u8 *p)
{
    u16 i;
    int j;
    for (i=0;i<6;i++) {
        j=B_PLIST_MAIN_GetOrderIndex(p,i);
        if (*(u16 *)(p+j*0x4c+8)) {
            int k=B_PLIST_MAIN_GetMonAnimState((char *)p+4+j*0x4c);
            B_PLIST_MAIN_SetActorAnimSeq(*(void **)(p+j*4+0x1ed8),k);
            CLACT_AddActorAnimFrame(*(void **)(p+j*4+0x1ed8),0x1000);
        }
    }
}
