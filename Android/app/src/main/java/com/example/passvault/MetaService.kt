package com.example.passvault

import okhttp3.RequestBody
import okhttp3.ResponseBody
import retrofit2.Call
import retrofit2.http.Body
import retrofit2.http.POST


interface MetaService {

    @POST(".")
    fun updateMeta(@Body msg: String?): Call<AccountData?>?

}