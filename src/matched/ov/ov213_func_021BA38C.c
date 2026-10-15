/*
 * function: COMM_BTL_DEMO_MAIN_InitRows
 * address: 0x021BA38C
 * packet: pkt_ov213_021BA38C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_IsFullPartyMode 0x021B9E50 thumb ov213
 *   COMM_BTL_DEMO_MAIN_InitRowContext 0x021BA268 thumb ov213
 */
typedef unsigned char u8;
typedef struct {char bytes[0x54];} Row;
typedef struct {int pad0;char *owner;char pad8[0x4834];Row rows[4];char pad498C[0x2C];int c;char pad49BC[12];u8 kind;char pad49C9[15];u8 flag;} Context;
extern int COMM_BTL_DEMO_MAIN_IsFullPartyMode(unsigned);
extern void COMM_BTL_DEMO_MAIN_InitRowContext(Row *,u8,u8,char *,void *,void *,int);
enum Count {CountZero,CountTwo=2,CountFour=4};
void COMM_BTL_DEMO_MAIN_InitRows(Context *p)
{
    int i;
    enum Count count;
    if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(p->kind)) count=CountTwo;
    else count=CountFour;
    for(i=0;i<count;i++)
        COMM_BTL_DEMO_MAIN_InitRowContext(&p->rows[i],p->kind,i,p->owner+i*16,(char *)p+0xC,(char *)p+0x24,p->c);
}
