/*
 * function: IRC_COMPATIBLE_StepRunnerRun
 * address: 0x021B6C20
 * packet: pkt_ov101_021B6C20
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_StepTable 0x021B74B8 data a4
 *   PROCSYS_Push 0x02031348 arm
 */
typedef struct Row { int a,b; int (*create)(int,int); void (*destroy)(int,int); } Row;
extern const Row IRC_COMPATIBLE_StepTable[];
extern void PROCSYS_Push(int,int,int,int);
int IRC_COMPATIBLE_StepRunnerRun(int *p,int index,int heap,int arg)
{
    int result;
    switch(p[1]) {
    case 0:
        if(IRC_COMPATIBLE_StepTable[index].create) result=IRC_COMPATIBLE_StepTable[index].create(heap,arg);
        else result=0;
        p[2]=result;
        p[1]=1;
        break;
    case 1:
        PROCSYS_Push(p[0],IRC_COMPATIBLE_StepTable[index].a,IRC_COMPATIBLE_StepTable[index].b,p[2]);
        p[1]=2;
        break;
    case 2:
        if(IRC_COMPATIBLE_StepTable[index].destroy) IRC_COMPATIBLE_StepTable[index].destroy(p[2],arg);
        p[1]=3;
        break;
    case 3:
        p[1]=0;
        return 1;
    }
    return 0;
}
