a = {{},
{1/5},
{3/40 , 9/40},
{44/45 , -56/15 , 32/9},
{19372/6561 , -25360/2187 , 64448/6561 , -212/729},
{9017/3168 , 355/33 , 46732/5247 , 49/176 , -5103/18656},
{35/384 , 0 , 500/1113 , 125/192 , -2187/6784 , 11/84 }};
c = {0, 1/5 , 3/10, 4/5, 8/9, 1, 1};
b = { 35/384 , 0 , 500/1113 , 125/192 , -2187/6784 , 11/84 , 0};
bb = { 5179/57600 , 0 , 7571/16695 , 393/640 , -92097/339200 , 187/2100 , 1/40 };
btilda = {
  t^2(3-2t)*b[[1]] + t(t-1)^2 - t^2(t-1)^2 * 5 * (2558722523 - 31403016 t)/11282082432,
0,
t^2(3-2t)*b[[3]]+ t^2*(t-1)^2 * 100 * (882725551 - 15701508 t)/32700410799,
t^2(3-2t)*b[[4]]+ t^2*(t-1)^2 * 25 * (443332067 - 31403016 t)/1880347072,
t^2(3-2t)*b[[5]]+ t^2*(t-1)^2 * 32805 * (23143187 - 3489224 t)/199316789632,
t^2(3-2t)*b[[6]]+ t^2*(t-1)^2 * 55 * (29972135 - 7076736 t)/822651844,
t^2(t-1)+t^2(t-1)^2 * 10 * (7414445 - 829305 t)/29380423
  };

digits = 50;

FormatList[l_] := NumberForm[N[#, digits], {Infinity,digits}]& /@ (l //. {el___, 0} -> {el} /. 0->0.) // ToString//InputForm;

FormatList @ a

FormatList @ b


FormatList @ bb

FormatList @ c

Length[a]

PolynomialListCoefficients[bs_] := Table[Coefficient[bs[[i]], t, j - 1], {i, 1, Length[bs]}, {j, 1, Max[Length @ #& /@ CoefficientList[bs, t]]}];

Max[Length @ #& /@ CoefficientList[btilda, t]]

FormatList@PolynomialListCoefficients[btilda]
