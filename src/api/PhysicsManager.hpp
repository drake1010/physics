////////////////////////////////////////////////////////////////////////////////////
//
//     _____    ____ _       ____ _        __ _      __ _  __ _  ______ _   ___ _
//    / /| |]  |  __ \\     / ___ \\      / \ \\    |   \\/   |]|  _____|] / ___|]
//   / //| |]  | |] \ \\   | |]  \_|]    / //\ \\   | |\ / /| |]| |]___ _ ( ((_ _
//  / //_| |]_ | |]  ) ))  | |]  __ _   / _____ \\  | |]\_/ | |]|  _____|] \___ \\
// |_____   _|]| |]_/ //   | |]__/  |] / //    \ \\ | |]    | |]| |]___ _   ___) ))
//       |_|]  |_____//     \_____/|]]/_//      \_\\|_|]    |_|]|_______|] |____//
// 
//
////////////////////////////////////////////////////////////////////////////////////
//
//
//  File    : PhysicsManager.hpp
//  Author  : Anthony Islas
//  Purpose : File Description
//  Group   : Api
//
//  TODO    : Anthony Islas
//
//  License : None
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef __API_PHYSICSMANAGER_H__
#define __API_PHYSICSMANAGER_H__

namespace physics
{

namespace api
{

class PhysicsManager : components::resources::Manager< PhysicalObject *, std::string >
{

public:
  PhysicsManager();
  ~PhysicsManager();

  void setClock( components::timing::Clock &clock );
  void adjustGravity( double fp64Gravity );

private:

  //\todo : Do we eventually want to turn managers into singletons?

  
};  

} // namespace api

} // namespace physics

#endif // __API_PHYSICSMANAGER_H__