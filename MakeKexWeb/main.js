var canv = document.getElementById('canv');
function resizeCanvas() {
  canv.height = window.innerHeight-50;
  canv.width  = window.innerWidth-50;
  ctx.font = "16pt monospace";
}
var ctx = canv.getContext('2d');

ctx.stroke();
ctx.moveTo(0, 0);
ctx.lineTo(100, 100);
ctx.stroke();

function avg(arr) {
  var s = 0, c = 0; for (var i of arr) { s += i; ++c; } return s/c; }

var pont = function (x,y) {
  this.x = x;
  this.y = y; }
pont.prototype.add = function (rhs) {
  this.x += rhs.x; this.y += rhs.y; return this; }
pont.prototype.sub = function (rhs) {
  this.x -= rhs.x; this.y -= rhs.y; return this; }
pont.prototype.to = function(to) {
  return new pont(to.x - this.x, to.y - this.y); }
pont.prototype.mul = function (rhs) { t
  this.x *= rhs; this.y *= rhs; return this; }
pont.prototype.div = function (rhs) {
  this.x /= rhs; this.y /= rhs; return this; }
pont.prototype.length = function() {
  return Math.sqrt(x*x + y*y); }
pont.prototype.norm = function () {
  return this.div(this.length); }
pont.prototype.cp = function() {
  return new pont(this.x, this.y); }
function addP(p1, p2) { return new pont(p1.x+p2.x, p1.y+p2.y); }
function subP(p1, p2) { return new pont(p1.x-p2.x, p1.y-p2.y); }
function mulP(p, rhs) { return new pont(p.x*rhs, p.y*rhs); }
function divP(p, rhs) { return new pont(p.x/rhs, p.y/rhs); }
function crsP(p1, p2) { return p1.x*p2.y - p1.y*p2.x; }
function dotP(p1, p2) { return p1.x*p2.x + p1.y*p2.y; }
function phiP(phi) { return new pont(Math.cos(phi), Math.sin(phi)); }
function rotP(p, o, np) {
  var rp = o.to(p);
  rp = new pont(rp.x*np.x - rp.y*np.y, rp.y*np.x + rp.x*np.y);
  return rp.add(o); }
function moveToP(p) { ctx.moveTo(p.x, p.y); }
function lineToP(p) { ctx.lineTo(p.x, p.y); }

var tria = function(p1, p2, p3) {
  this.p1 = p1;
  this.p2 = p2;
  this.p3 = p3; }
tria.prototype.ponts = function* () {
  yield this.p1; yield this.p2; yield this.p3; }
tria.prototype.edges = function* () {
  yield this.p1.to(this.p2);
  yield this.p2.to(this.p3);
  yield this.p3.to(this.p1); }
tria.prototype.area = function () {
  return Math.abs(this.p2.sub(this.p1).crs(p3.sub(this.p1)))/2; }
tria.prototype.median = function () {
  return addP(this.p1, addP(this.p2, this.p3)).div(3); }
tria.prototype.isIn = function (p) {
  var z1 = crsP(this.p1.to(p2), this.p1.to(p));
  var z2 = crsP(this.p2.to(p3), this.p2.to(p));
  var z3 = crsP(this.p3.to(p1), this.p3.to(p));
  return abs(Math.sign(z1) + Math.sign(z2) + Math.sign(z3)) == 3 ||
    z1*z2*z3 == 0; }
tria.prototype.draw = function () {
  ctx.beginPath();
  moveToP(this.p3);
  lineToP(this.p1);
  lineToP(this.p2);
  lineToP(this.p3);
  ctx.stroke(); }
tria.prototype.mov = function (vt) {
  this.p1.add(vt); this.p2.add(vt); this.p3.add(vt); }
tria.prototype.rot = function (o, np) {
  this.p1 = rotP(this.p1, o, np);
  this.p2 = rotP(this.p2, o, np);
  this.p3 = rotP(this.p3, o, np); }
function crossTr(tr1, tr2) {
  for (var p of tr1.ponts()) {
    if(tr2.isIn(p)) return true;  }
  for (var p of tr2.ponts()) {
    if(tr1.isIn(p)) return true;  }
  return false; }

var tri = new tria(new pont(150,200), new pont(215,50), new pont(100,110))

var step = 0;
function loopMain (dt) {
  ctx.clearRect(0, 0, canv.width, canv.height);
  ctx.fillText(1/dt, 0, canv.height-30);
  ctx.beginPath();
  ctx.moveTo(-1e48, 50);
  ctx.lineTo(1e48, 50)
  ctx.stroke();
  tri.draw();
  tri.rot(new pont(200,200), phiP(dt*Math.PI))
}

var loop = setInterval(function () {
  var last = new Date();
  return function () {
    loopMain((-last.getTime() + (last=new Date()).getTime())/1000);
    step++; }
}(), 5);

//*/
