### SFML-TMX-Map
Supports tmx maps up to 0.18.2 with CSV,base64 and XML \n
In the near future object layer drawing  will be added 

Loading map created in Tiled TMX
```sh
Map map("name.tmx");
```
Drawing a Map
```sh
MapDrawable MapDraw(map);
...
window.draw(MapDraw);
```
License
Zlib
