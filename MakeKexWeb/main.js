var canv = document.getElementById('canv');
var ctx = canv.getContext('2d');

ctx.font = "16pt monospace";

ctx.stroke();
ctx.moveTo(0, 0);
ctx.lineTo(100, 100);
ctx.stroke();

function sgn(z) { return z>0?1:z<0?-1:0; }
function avg(arr) {
  var s = 0, c = 0; for (var i of arr) { s += i; ++c; } return s/c;
}

var pont = function (x,y) {
  this.x = x;
  this.y = y;
  this.add = function (rhs) { this.x += rhs.x; this.y += rhs.y; return this; }
  this.sub = function (rhs) { this.x -= rhs.x; this.y -= rhs.y; return this; }
  this.to = function(to) { return new pont(to.x - this.x, to.y - this.y); }
  this.mul = function (rhs) { this.x *= rhs; this.y *= rhs; return this; }
  this.div = function (rhs) { this.x /= rhs; this.y /= rhs; return this; }
  this.length = function() { return Math.sqrt(x*x + y*y); }
  this.norm = function () { return this.div(this.length); }
  this.cp = function() { return new pont(this.x, this.y); }
}
function addP(p1, p2) { return new pont(p1.x+p2.x, p1.y+p2.y); }
function subP(p1, p2) { return new pont(p1.x-p2.x, p1.y-p2.y); }
function mulP(p, rhs) { return new pont(p.x*rhs, p.y*rhs); }
function divP(p, rhs) { return new pont(p.x/rhs, p.y/rhs); }
function crsP(p1, p2) { return p1.x*p2.y - p1.y*p2.x; }
function dotP(p1, p2) { return p1.x*p2.x + p1.y*p2.y; }
function phiP(phi) { return new pont(cos(phi), sin(phi)); }
function rotate(p, o, np) {
  var rp = o.to(p);
  rp = new pont(rp.x*np.x - rp.y*np.y, rp.y*np.x + rp.x*np.y);
  return rp.add(o);
}

ctx.moveToP = function (p) { ctx.moveTo(p.x, p.y); }
ctx.lineToP = function (p) { ctx.lineTo(p.x, p.y); }
ctx.drawLineP = function (from, to) {
  ctx.moveTo(from.x, from.y);
  ctx.lineTo(to.x, to.y);
  ctx.stroke();
}

var triangle = function(p1, p2, p3) {
  this.p1 = p1;
  this.p2 = p2;
  this.p3 = p3;
  this.area = function () { return Math.abs(p2.sub(p1).crs(p3.sub(p1))) /2; }
  this.points = function* () { yield p1; yield p2; yield p3; }
  this.edges = function* () {yield p1.to(p2); yield p2.to(p3); yield p3.to(p1);}
  this.isIn = function (p) {
    var z1 = crsP(p1.to(p2), p1.to(p));
    var z2 = crsP(p2.to(p3), p2.to(p));
    var z3 = crsP(p3.to(p1), p3.to(p));
    return abs(sgn(z1) + sgn(z2) + sgn(z3)) == 3 || z1*z2*z3 == 0;
  }
  this.draw = function () {
    ctx.moveToP(tri.p3);
    ctx.lineToP(tri.p1);
    ctx.lineToP(tri.p2);
    ctx.lineToP(tri.p3);
    ctx.stroke(); }
  this.move = function (vt) { p1.add(vt); p2.add(vt); p3.add(vt); }
}
function crossTr(tr1, tr2) {
  for (var p of tr1.points()) {
    if(tr2.isIn(p)) return true;
  }
  for (var p of tr2.points()) {
    if(tr1.isIn(p)) return true;
  }
  return false;
}

function loopMain (dt) {
      ctx.clearRect(0, 0, canv.width, canv.height);
      ctx.strokeText(1000/dt, 0, 400);
}

setInterval(function () {
  var last = new Date();
  return function () { loopMain(-last.getTime() + (last=new Date()).getTime()) }
}(), 0);

//*/
