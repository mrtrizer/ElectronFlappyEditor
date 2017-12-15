#include "Renderer.h"

#include <memory>

#include <Sdl2Manager.h>
#include <Entity.h>
#include <SceneManager.h>
#include <GLRenderManager.h>
#include <GLRenderElementFactory.h>
#include <ScreenManager.h>
#include <ThreadManager.h>

using namespace flappy;

std::shared_ptr<Entity> rootEntity;

void initSDLRenderer() {
    LOGW("initSDLRenderer");
    rootEntity = std::make_shared<Entity>();
    rootEntity->component<ThreadManager>();
    rootEntity->createComponent<Sdl2Manager>();
    rootEntity->createComponent<ScreenManager>(600, 600);

    // Scene
    auto sceneEntity = rootEntity->createEntity();
    sceneEntity->component<SceneManager>()->setMainCamera(sceneEntity->component<CameraComponent>());
    sceneEntity->component<CameraComponent>()->setSize({600, 600});
    sceneEntity->component<GLRenderManager>();
    sceneEntity->component<GLRenderElementFactory>();
}
