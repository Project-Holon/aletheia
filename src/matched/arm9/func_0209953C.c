/*
 * function: __kernel_rem_pio2
 * address:  0x0209953C
 * packet:   pkt_02098B44
 * region:   arm9
 * compiler: 1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _dsub        0x0209AF34  arm
 *   _dmul        0x0209B2E8  arm
 *   _dadd        0x0209AC04  arm
 *   _dfix        0x0209C508  arm
 *   _dflt        0x0209B750  arm
 *   _deq         0x0209BA3C  arm
 *   _dgeq        0x0209B7CC  arm
 *   func_02097990  0x02097990  arm
 *   func_0209A524  0x0209A524  arm
 *   init_jk      0x020A64A8  data
 *   PIo2         0x020A64B8  data
 *
 * fdlibm __kernel_rem_pio2(x, y, e0, nx, prec, ipio2), k_rem_pio2.c, the old
 * revision (the prec 1/2 arm computes fw = fq[0]-fw, not fq[0]-y[0]).  Called
 * only by __ieee754_rem_pio2 (unit_02098B44.c).  EXACT under dsi/1.2, 62 of 62
 * relocations resolved.  Two loops differ from the fdlibm text: the f[] setup
 * loop and the recompute distill loop each carry an explicit if with the loop
 * condition in front of the for, which mwcc keeps as a second guard next to
 * the rotation guard (image +0x84 cmp r8,#0 / blt and +0x194 cmpgt r0,#0).
 * The f[] loop's i = 0 sits after j and m; with it first, or in the for
 * header, i and j swap registers in the recompute loop.
 */

extern const int init_jk[];
extern const double PIo2[];
extern double func_02097990(double x, int n);
extern double func_0209A524(double x);

static const double
zero   = 0.0,
one    = 1.0,
two24  = 1.67772160000000000000e+07,
twon24 = 5.96046447753906250000e-08;

int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const int *ipio2)
{
	int jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
	double z,fw,f[20],fq[20],q[20];

	jk = init_jk[prec];
	jp = jk;

	jx =  nx-1;
	jv = (e0-3)/24; if(jv<0) jv=0;
	q0 =  e0-24*(jv+1);

	j = jv-jx; m = jx+jk; i = 0;
	if(m>=0) for(;i<=m;i++,j++) f[i] = (j<0)? zero : (double) ipio2[j];

	for (i=0;i<=jk;i++) {
	    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j]; q[i] = fw;
	}

	jz = jk;
recompute:
	i=0; j=jz; z=q[jz]; if(j>0) for(;j>0;i++,j--) {
	    fw    =  (double)((int)(twon24* z));
	    iq[i] =  (int)(z-two24*fw);
	    z     =  q[j-1]+fw;
	}

	z  = func_02097990(z,q0);
	z -= 8.0*func_0209A524(z*0.125);
	n  = (int) z;
	z -= (double)n;
	ih = 0;
	if(q0>0) {
	    i  = (iq[jz-1]>>(24-q0)); n += i;
	    iq[jz-1] -= i<<(24-q0);
	    ih = iq[jz-1]>>(23-q0);
	}
	else if(q0==0) ih = iq[jz-1]>>23;
	else if(z>=0.5) ih=2;

	if(ih>0) {
	    n += 1; carry = 0;
	    for(i=0;i<jz ;i++) {
		j = iq[i];
		if(carry==0) {
		    if(j!=0) {
			carry = 1; iq[i] = 0x1000000- j;
		    }
		} else  iq[i] = 0xffffff - j;
	    }
	    if(q0>0) {
	        switch(q0) {
	        case 1:
	    	   iq[jz-1] &= 0x7fffff; break;
	    	case 2:
	    	   iq[jz-1] &= 0x3fffff; break;
	        }
	    }
	    if(ih==2) {
		z = one - z;
		if(carry!=0) z -= func_02097990(one,q0);
	    }
	}

	if(z==zero) {
	    j = 0;
	    for (i=jz-1;i>=jk;i--) j |= iq[i];
	    if(j==0) {
		for(k=1;iq[jk-k]==0;k++);

		for(i=jz+1;i<=jz+k;i++) {
		    f[jx+i] = (double) ipio2[jv+i];
		    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j];
		    q[i] = fw;
		}
		jz += k;
		goto recompute;
	    }
	}

	if(z==0.0) {
	    jz -= 1; q0 -= 24;
	    while(iq[jz]==0) { jz--; q0-=24;}
	} else {
	    z = func_02097990(z,-q0);
	    if(z>=two24) {
		fw = (double)((int)(twon24*z));
		iq[jz] = (int)(z-two24*fw);
		jz += 1; q0 += 24;
		iq[jz] = (int) fw;
	    } else iq[jz] = (int) z ;
	}

	fw = func_02097990(one,q0);
	for(i=jz;i>=0;i--) {
	    q[i] = fw*(double)iq[i]; fw*=twon24;
	}

	for(i=jz;i>=0;i--) {
	    for(fw=0.0,k=0;k<=jp&&k<=jz-i;k++) fw += PIo2[k]*q[i+k];
	    fq[jz-i] = fw;
	}

	switch(prec) {
	    case 0:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		break;
	    case 1:
	    case 2:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		fw = fq[0]-fw;
		for (i=1;i<=jz;i++) fw += fq[i];
		y[1] = (ih==0)? fw: -fw;
		break;
	    case 3:
		for (i=jz;i>0;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (i=jz;i>1;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (fw=0.0,i=jz;i>=2;i--) fw += fq[i];
		if(ih==0) {
		    y[0] =  fq[0]; y[1] =  fq[1]; y[2] =  fw;
		} else {
		    y[0] = -fq[0]; y[1] = -fq[1]; y[2] = -fw;
		}
	}
	return n&7;
}
