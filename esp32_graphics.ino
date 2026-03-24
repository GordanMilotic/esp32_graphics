#define SPEED  15 //brzina slanja podataka na osciloskop

void drawPoints(int points[][2], int numPoints) {
  for(int i = 0; i < numPoints - 1; i++) {
    int x1 = points[i][0];
    int y1 = points[i][1];
    int x2 = points[i+1][0];
    int y2 = points[i+1][1];
    //bresenham
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int error = dx - dy;
    int x = x1, y = y1;
    
    while(true) {
      dacWrite(25, constrain(x, 0, 255));
      dacWrite(26, constrain(y, 0, 255));
      delayMicroseconds(SPEED);
      
      if(x == x2 && y == y2) break;
      
      int e2 = 2 * error;
      if(e2 > -dy) { error -= dy; x += sx; }
      if(e2 < dx) { error += dx; y += sy; }
    }
  }
}

void loop() {
  
  // u slucaju zamjene osi (krivog prikaza) koordinatnog sustava, prespojiti sondu x na sondu y i obrnuto
  while(1) {
    int points[][2] = {
      /*
      -petlja za ubacivanje koordinata, sintaksa {x, y}
      -dimenzije koordinatnog sustava su 256 x 256
      -krajnje tocke (0, 0) (0, 256) (256, 256) (256, 0)
      -namjestiti time/div i poziciju po kanalu
      */
    };
    int numPoints = sizeof(points) / sizeof(points[0]);
    drawPoints(points, numPoints);
  }
}

void setup() {}

