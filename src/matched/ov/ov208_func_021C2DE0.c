/*
 * function: ZUKAN_DETAIL_VOICE_SetNumberDigits
 * address: 0x021C2DE0
 * packet: pkt_ov208_021C2DE0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   data_021C86EC 0x021C86EC data ov208 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct Indices { u8 v[4]; };
extern const struct Indices data_021C86EC;
extern void CLACT_SetActorAnimIndex(int a0, int a1);
void ZUKAN_DETAIL_VOICE_SetNumberDigits(void *unused,u8 *p,void *unused2,int first,u16 second)
{
    struct Indices ids;
    u16 digits[4];
    u8 i;
    ids=data_021C86EC;
    digits[0]=first/10;
    if(digits[0]>9)digits[0]=9;
    digits[1]=first%10;
    digits[2]=second/10;
    if(digits[2]>9)digits[2]=9;
    digits[3]=second%10;
    for(i=0;i<4;i++)
        CLACT_SetActorAnimIndex((int)(*(struct Obj **)(p+ids.v[i]*4+0x9c)),digits[i]);
}
