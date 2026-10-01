/*
 * function: func_021848F4
 * address: 0x021848F4
 * packet: pkt_ov219_021848F4
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare oldx before a named base pointer; this puts oldx in r5
 * and base in r6. Const on the parameter alone left their five-byte swap.
 */
void func_021848F4(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance)
{
    int oldx;
    const char *base=p;
    int xf=0,yf=0,dx=0,dy=0;
    oldx=*(int *)(base+0xc364);
    if(oldx!=0xffff){
        dx=oldx-x;
        if(dx<0){dx^=-1;xf=0x10;}
        else if(dx>0)xf=0x20;
    }
    *xflag=xf;*xdistance=dx&63;
    if(*(int *)(base+0xc368)!=0xffff){
        dy=*(int *)(base+0xc368)-y;
        if(dy<0){dy^=-1;yf=0x80;}
        else if(dy>0)yf=0x40;
    }
    *yflag=yf;*ydistance=dy&63;
}
