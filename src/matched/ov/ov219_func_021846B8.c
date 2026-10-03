/*
 * function: func_021846B8
 * address: 0x021846B8
 * packet: pkt_ov219_021846B8
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: lead124B followed by separately matched92B func_02184734; no unit, follower has its own shard.
 * lever: typed48-byte record members keep byte offset live rather than caching p+offset as a raw pointer.
 * symbols:
 *   d_02185F28 0x02185F28 data a4
 *   func_021858BC 0x021858BC thumb ov219
 *   func_0200949C 0x0200949C thumb
 */
typedef unsigned short u16;
typedef struct { int words[9]; } Matrix;
typedef struct {short x,y;Matrix matrix;u16 state,a,b,pad;} Record;
typedef struct {int words[6];Record records[];} State;
extern const Matrix d_02185F28;
extern void func_021858BC(Matrix *,int *);
extern int func_0200949C(void *,int,int);
void func_021846B8(State *p,int index,int x,int y,u16 a,u16 b)
{
    Matrix matrix=d_02185F28;
    int angles[3];
    p->records[index].x=x;
    p->records[index].y=y;
    angles[0]=x;angles[1]=y;angles[2]=0;
    func_021858BC(&matrix,angles);
    p->records[index].matrix=matrix;
    p->records[index].state=func_0200949C((void *)p->words[4],a,b);
    p->records[index].a=a;
    p->records[index].b=b;
}
