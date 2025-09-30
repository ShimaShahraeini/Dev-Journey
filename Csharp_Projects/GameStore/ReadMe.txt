# GameStore API

A minimal ASP.NET Core Web API project built while learning backend development with .NET.  
It simulates a simple game store backend, including models, EF Core data access, DTOs, mappings, and CRUD endpoints for games and genres.

> **Learning context:** This project was built step-by-step while following the [ASP.NET Core Beginner Course](https://youtu.be/AhAxLiGC7Pc?si=AHX0u4nu6YjKiQoG).
 Every concept was new to me — from C# DTOs to EF Core migrations — so this repo doubles as both a practice app and a learning log.

---

## Overview
The API supports:
- Listing, creating, updating, and deleting games
- Returning genres and eager loading genres when querying games
- Using DTOs and mapping to avoid returning entities directly
- Input validation via data annotations
- Automatic migrations at startup
- Interactive API testing via Swagger

---

## Tech Stack
- **.NET 8** (ASP.NET Core Web API)
- **Entity Framework Core** with SQLite
- **Minimal APIs** with grouped endpoints
- **Swashbuckle/Swagger** for interactive API documentation
- **MinimalApis.Extensions** NuGet package for endpoint validation

---

## Endpoints

### Games (`/games`)
- `GET /games` → List all games (with Genre eager loaded)
- `GET /games/{id}` → Get details of a single game
- `POST /games` → Create a new game (validates input)
- `PUT /games/{id}` → Update a game
- `DELETE /games/{id}` → Delete a game

### Genres (`/genres`)
- `GET /genres` → List all genres (pre-seeded)


## Sample Requests & Responses
you can get the sampels from games.http and genres.http under properties folder.
you can test the project and send request via these files or use Swagger UI
Open in browser: http://localhost:5222/swagger


## What I Learned

Minimal API pattern: mapping endpoints with MapGroup, MapGet, MapPost, etc.

Dependency Injection: registering DbContext and resolving it in endpoints.

Entity Framework Core: setting up GameStoreContext, DbSet<Game>, DbSet<Genre>, and running migrations.

Data seeding: pre-populating genres in OnModelCreating.

DTOs & Mapping: creating DTOs for input/output and using extension methods.

Validation: using [Required], [Range], [StringLength], [DataType].

Eager loading: using .Include() for related entities (Game.Genre).

Swagger / OpenAPI: generating interactive documentation for endpoints.

Async/Await: handling DB calls non-blockingly for scalability.

Troubleshooting: resolving build errors, missing packages, and DI issues.


## How to Run

### Prerequisites:
.NET 8 SDK

### Steps:
1.
git clone <your-repo-url>
cd GameStore

2.
dotnet restore

3.
# Run migrations
dotnet ef migrations add InitialCreate -p GameStore.Api -s GameStore.Api
dotnet ef database update -p GameStore.Api -s GameStore.Api

4.
# Run the API
cd GameStore.Api
dotnet run

5.
# Swagger UI
Open in browser: http://localhost:5222/swagger
