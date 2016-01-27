var canv = getElementById('canvas');
var ctx = canv.getContext('2d');

ctx.stroke();
ctx.moveTo(0, 0);
ctx.lineTo(100, 100);
ctx.stroke();

function pont(x,y) {
  this.x = x;
  this.y = y;
  this.add = function (rhs) { return new pont(this.x + rhs.x, this.y + rhs.y); }
  this.sub = function (rhs) { return new pont(this.x - rhs.x, this.y - rhs.y); }
  this.mul = function (rhs) { return new pont(this.x * rhs, this.y * rhs); }
}

ctx.drawLine = function (from, to) {
  ctx.moveTo(from.x, from.y);
  ctx.lineTo(to.x, to.y);
  ctx.stroke();
}

class triangle {
  constructor(p1, p2, p3) {
    this.p1 = p1;
    this.p2 = p2;
    this.p3 = p3;
  }
}

ctx.drawTriangle(tri) {
  ctx.moveTo(tri.p1.x, tri.p1.y);
  ctx.lineTo(tri.p2.x, tri.p2.y);
  ctx.lineTo(tri.p3.x, tri.p3.y);
  ctx.lineTo(tri.p1.x, tri.p1.y);
}
