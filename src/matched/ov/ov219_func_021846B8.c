/*
 * function: BEACON_DETAIL_SetRecord
 * address: 0x021846B8
 * packet: pkt_ov219_021846B8
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: lead124B followed by separately matched92B BEACON_DETAIL_MarkCurrentRecord; no unit, follower has its own shard.
 * lever: typed48-byte record members keep byte offset live rather than caching p+offset as a raw pointer.
 * symbols:
 *   d_02185F28 0x02185F28 data a4
 *   BEACON_DETAIL_SetupRecordCalc 0x021858BC thumb ov219
 *   func_0200949C 0x0200949C thumb
 */
typedef unsigned short u16;
typedef struct { int words[9]; } Matrix;
typedef struct {short x,y;Matrix matrix;u16 state,a,b,pad;} Record;
typedef struct {int words[6];Record records[];} State;
extern const Matrix d_02185F28;
extern void BEACON_DETAIL_SetupRecordCalc(Matrix *,int *);
typedef unsigned int   u32;
struct Sub02009470Obj;
extern u32 func_0200949C(const struct Sub02009470Obj *obj, int row, int col);
void BEACON_DETAIL_SetRecord(State *p,int index,int x,int y,u16 a,u16 b)
{
    Matrix matrix=d_02185F28;
    int angles[3];
    p->records[index].x=x;
    p->records[index].y=y;
    angles[0]=x;angles[1]=y;angles[2]=0;
    BEACON_DETAIL_SetupRecordCalc(&matrix,angles);
    p->records[index].matrix=matrix;
    p->records[index].state=func_0200949C((void *)p->words[4],a,b);
    p->records[index].a=a;
    p->records[index].b=b;
}
