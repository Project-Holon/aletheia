/*
 * function: BEACON_DETAIL_Delete3DObjects
 * address: 0x0218562C
 * packet: pkt_ov219_0218562C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02048C4C is the non-C veneer ldr ip,[pc]; bx ip; .word 020307B0 (show 02048C4C..02048C58). All concrete bytes match, but the veneer call has no outside witness. the integrator owns ARM9; no overlay follower filed.
 * extent: lead ends 021856CC; unlabelled initialization follower 021856CC..02185728 is omitted while ARM9 blocks the caller.
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 *   d_02185E18 0x02185E18 data a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 index,member;} Entry;
extern const Entry d_02185E18[];
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_LIGHT_DeleteSlots(void *);
struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
void BEACON_DETAIL_Delete3DObjects(char *p)
{
    u32 i;
    char *row;
    G3D_CAMERA_Delete(*(void **)(p+0xC36C));
    G3D_LIGHT_DeleteSlots(*(void **)(p+0xC370));
    G3D_SYSTEM_DeleteObject(*(void **)(p+0xC3A4));
    G3D_SYSTEM_DeleteRender(*(void **)(p+0xC38C));
    G3D_SYSTEM_FreeVramTexture(*(u32 **)(p+0xC374));
    G3D_SYSTEM_DeleteResource(*(void **)(p+0xC374));
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        G3D_SYSTEM_DeleteObject(*(void **)(row+0xC3A8));
        G3D_SYSTEM_DeleteRender(*(void **)(row+0xC390));
        G3D_SYSTEM_FreeVramTexture(*(u32 **)(row+0xC378));
        G3D_SYSTEM_DeleteResource(*(void **)(row+0xC378));
    }
    *(u32 *)(p+0xC3A4)=0;
}
