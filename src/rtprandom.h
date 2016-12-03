/*

  This file is a part of JRTPLIB
  Copyright (c) 1999-2004 Jori Liesenborgs

  Contact: jori@lumumba.luc.ac.be

  This library was developed at the "Expertisecentrum Digitale Media"
  (http://www.edm.luc.ac.be), a research center of the "Limburgs Universitair
  Centrum" (http://www.luc.ac.be). The library is based upon work done for 
  my thesis at the School for Knowledge Technology (Belgium/The Netherlands).

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included
  in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.

*/

#ifndef RTPRANDOM_H

#define RTPRANDOM_H

#include "rtpconfig.h"
#include "rtptypes.h"
#include <stdlib.h>

class RTPRandom
{
public:
	RTPRandom();
	~RTPRandom();
	u_int8_t GetRandom8();
	u_int16_t GetRandom16();
	u_int32_t GetRandom32();
	double GetRandomDouble(); // returns random value between 0.0 and 1.0
private:
#ifdef RTP_SUPPORT_GNUDRAND
	struct drand48_data drandbuffer;
#else
#ifdef RTP_SUPPORT_RANDR
	unsigned int state;
#else
	static bool init;
#endif // RTP_SUPPORT_RANDR
#endif // RTP_SUPPORT_GNUDRAND
};

#endif // RTPRANDOM_H
