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
//  File    : PhysicalObject.hpp
//  Author  : Anthony Islas
//  Purpose : File Description
//  Group   : Api
//
//  TODO    : Anthony Islas
//
//  License : None
//
////////////////////////////////////////////////////////////////////////////////////
#ifndef __API_PHYSICALOBJECT_H__
#define __API_PHYSICALOBJECT_H__

namespace physics
{

namespace api
{
  

class PhysicalObject
{

public:
  PhysicalObject();
  virtual ~PhysicalObject();

  int i32Xpos( ) { return static_cast< int >( fp64Xpos_ ); }
  int i32Ypos( ) { return static_cast< int >( fp64Ypos_ ); }
  int i32Zpos( ) { return static_cast< int >( fp64Zpos_ ); }

  float fp32Xpos( ) { return static_cast< float >( fp64Xpos_ ); }
  float fp32Ypos( ) { return static_cast< float >( fp64Ypos_ ); }
  float fp32Zpos( ) { return static_cast< float >( fp64Zpos_ ); }

  void update( );

  void setGravityPercent( );

  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  //
  // Accelerations
  //
  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  void setXYZaccel( 
                    float fp32Xval, 
                    float fp32Yval,
                    float fp32Zval
                    );
  void setXYZaccel( std::vector< float > vXYZval );

  void setXaccel( float fp32Xval );
  void setYaccel( float fp32Yval );
  void setZaccel( float fp32Zval );


  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  //
  // Velocities
  //
  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  void setXYZvelocity( 
                    float fp32Xval, 
                    float fp32Yval,
                    float fp32Zval
                    );
  void setXYZvelocity( std::vector< float > vXYZval );

  void setXvelocity( float fp32Xval );
  void setYvelocity( float fp32Yval );
  void setZvelocity( float fp32Zval );



  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  //
  // Positions
  //
  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  void setXYZposition( 
                    float fp32Xval, 
                    float fp32Yval,
                    float fp32Zval
                    );
  void setXYZposition( std::vector< float > vXYZval );

  void setXposition( float fp32Xval );
  void setYposition( float fp32Yval );
  void setZposition( float fp32Zval );

protected:

  double fp64Xaccel_;
  double fp64Yaccel_;
  double fp64Zaccel_;

  double fp64Xvel_;
  double fp64Yvel_;
  double fp64Zvel_;

  double fp64Xpos_;
  double fp64Ypos_;
  double fp64Zpos_;

  float fp32GravityPercent_;

};


} // namespace api

} // namespace physics

#endif // __API_PHYSICALOBJECT_H__