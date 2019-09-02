void CreateUserUsingLambda(firebase::auth::Auth* auth) {
  // Callbacks work the same for any firebase::Future.
  firebase::Future<firebase::auth::User*> result =
      auth->CreateUserWithEmailAndPasswordLastResult();

  // The lambda has the same signature as the callback function.
  result.OnCompletion(
      [](const firebase::Future<firebase::auth::User*>& result,
         void* user_data) {
        // `user_data` is the same as &my_program_context, below.
        // Note that we can't capture this value in the [] because std::function
        // is not supported by our minimum compiler spec (which is pre C++11).
        MyProgramContext* program_context =
            static_cast<MyProgramContext*>(user_data);

        // Process create user result...
        (void)program_context;
      },
      &my_program_context);
}
