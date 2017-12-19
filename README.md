Experiment with using of Electron as a platform for development of an eiditor
for game engine.

#Files
+ addon.cc - node addon
+ binding.gyp - build configuration
+ main.js - core process
+ index.html - browser process
+ renderer - Flappy project statically linked to addon. It creates SDL window.
+ test_project - FlappyEngine project, dynamically linked to addon.cc. It represents edited project.

#Build
1. clone electron repository and run (I used v1.7.9)
```
./scripts/bootstrap.py
```
2. setup pathes in `binding.gyp` to match Electron dir
3. run `npm install` in project dirty
4. run `./node_modules/.bin/electron-rebuild -f` to build addons
5. build dir `test_project` as FlappyTools project to shared lib
6. build dir `renderer` as FlappyTools project to shared lib
7. finally launch `npm start`

Last console output:
```
> FlappyEditor@0.0.1 start /Users/deniszdorovtsov/Projects/FlappyEditor
> electron .

2017-12-19 21:40:59.296 Electron[317:30939347] *** WARNING: Textured window <AtomNSWindow: 0x7ffdecb70ca0> is getting an implicitly transparent titlebar. This will break when linking against newer SDKs. Use NSWindow's -titlebarAppearsTransparent=YES instead.
 [WARNING] initSDLRenderer
 [INFO] Init flappy::ThreadManager
 [INFO] Init flappy::IGLManager
 [INFO] SDL GL Context version: 2.1
 [INFO] Init flappy::ScreenManager
 [INFO] Init flappy::SceneManager
 [INFO] Init flappy::CameraComponent
 [INFO] Init flappy::RenderManager
 [INFO] OpenGL Version: 2.1 INTEL-10.28.29

 [INFO] Init flappy::RenderElementFactory
200
before Size()
```

This is unsuccessful experiment because I didn't manage to access NativeImage class
from addon because this class is not exported. I tried to link chromiumcontent statically and
dynamically but no profit. App crashed on trying to access methods of native image.
