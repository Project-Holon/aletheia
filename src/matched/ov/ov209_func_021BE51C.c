/*
 * function: ZUKAN_LIST_MoveCursorActor
 * address: 0x021BE51C
 * packet: pkt_ov209_021BE51C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Row expression assigned back to index keeps the entry register; 021BE586 is two zero alignment bytes.
 * symbols:
 *   ZUKAN_LIST_GetActorVisible 0x021BD8F4 thumb ov209
 *   ZUKAN_LIST_GetActorPos 0x021BD958 thumb ov209
 *   ZUKAN_LIST_GetActorAnimSeq 0x021BD8B0 thumb ov209
 *   ZUKAN_LIST_StartActorAnim 0x021BD890 thumb ov209
 */
typedef unsigned short u16;
extern unsigned int ZUKAN_LIST_GetActorVisible(char *p, unsigned int idx);
typedef signed short   s16;
typedef unsigned int   u32;
extern void ZUKAN_LIST_GetActorPos(char *p, u32 idx, s16 *x, s16 *y, u16 space);
extern int ZUKAN_LIST_GetActorAnimSeq(char *,int);
extern void ZUKAN_LIST_StartActorAnim(char *,int,int);
void ZUKAN_LIST_MoveCursorActor(char *p,int index)
{
    unsigned i;
    short pos[2];
    index=index*24+8;
    for(i=10;i<26;i++){
        if(ZUKAN_LIST_GetActorVisible((char *)p,i)==0)ZUKAN_LIST_StartActorAnim(p,i,0);
        else{
            ZUKAN_LIST_GetActorPos(p,i,&pos[1],&pos[0],0);
            if(index==pos[0]){if(ZUKAN_LIST_GetActorAnimSeq(p,i)!=1)ZUKAN_LIST_StartActorAnim(p,i,1);}
            else ZUKAN_LIST_StartActorAnim(p,i,0);
        }
    }
}
